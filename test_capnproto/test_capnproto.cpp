#include "myproto.capnp.h"
#include <capnp/message.h>
#include <capnp/serialize-packed.h>
#include <iostream>

using addressbook::AddressBook;
using addressbook::Person;

void writeAddressBook(int fd) {
  ::capnp::MallocMessageBuilder message;

  AddressBook::Builder addressBook = message.initRoot<AddressBook>();
  ::capnp::List<Person>::Builder people = addressBook.initPeople(2);

  Person::Builder alice = people[0];
  alice.setId(123);
  alice.setName("Alice");
  alice.setEmail("alice@example.com");
  // Type shown for explanation purposes; normally you'd use auto.
  ::capnp::List<Person::PhoneNumber>::Builder alicePhones = alice.initPhones(1);
  alicePhones[0].setNumber("555-1212");
  alicePhones[0].setType(Person::PhoneNumber::Type::MOBILE);
  alice.getEmployment().setSchool("MIT");

  Person::Builder bob = people[1];
  bob.setId(456);
  bob.setName("Bob");
  bob.setEmail("bob@example.com");
  auto bobPhones = bob.initPhones(2);
  bobPhones[0].setNumber("555-4567");
  bobPhones[0].setType(Person::PhoneNumber::Type::HOME);
  bobPhones[1].setNumber("555-7654");
  bobPhones[1].setType(Person::PhoneNumber::Type::WORK);
  bob.getEmployment().setUnemployed();

  writePackedMessageToFd(fd, message);
}

void printAddressBook(int fd) {
  ::capnp::PackedFdMessageReader message(fd);

  AddressBook::Reader addressBook = message.getRoot<AddressBook>();

  for (Person::Reader person : addressBook.getPeople()) {
    std::cout << person.getName().cStr() << ": " << person.getEmail().cStr()
              << std::endl;
    for (Person::PhoneNumber::Reader phone : person.getPhones()) {
      const char *typeName = "UNKNOWN";
      switch (phone.getType()) {
      case Person::PhoneNumber::Type::MOBILE:
        typeName = "mobile";
        break;
      case Person::PhoneNumber::Type::HOME:
        typeName = "home";
        break;
      case Person::PhoneNumber::Type::WORK:
        typeName = "work";
        break;
      }
      std::cout << "  " << typeName << " phone: " << phone.getNumber().cStr()
                << std::endl;
    }
    Person::Employment::Reader employment = person.getEmployment();
    switch (employment.which()) {
    case Person::Employment::UNEMPLOYED:
      std::cout << "  unemployed" << std::endl;
      break;
    case Person::Employment::EMPLOYER:
      std::cout << "  employer: " << employment.getEmployer().cStr()
                << std::endl;
      break;
    case Person::Employment::SCHOOL:
      std::cout << "  student at: " << employment.getSchool().cStr()
                << std::endl;
      break;
    case Person::Employment::SELF_EMPLOYED:
      std::cout << "  self-employed" << std::endl;
      break;
    }
  }
}

int main(int argc, char **argv) {
  std::cout << "hello capnproto." << std::endl;

  if (argc != 2) {
    std::cerr << "Missing arg." << std::endl;
    return 1;
  } else if (strcmp(argv[1], "write") == 0) {
    writeAddressBook(1);
  } else if (strcmp(argv[1], "read") == 0) {
    printAddressBook(0);
    // #if !CAPNP_LITE
    //   } else if (strcmp(argv[1], "dwrite") == 0) {
    //     StructSchema schema = Schema::from<AddressBook>();
    //     dynamicWriteAddressBook(1, schema);
    //   } else if (strcmp(argv[1], "dread") == 0) {
    //     StructSchema schema = Schema::from<AddressBook>();
    //     dynamicPrintMessage(0, schema);
    // #endif
  } else {
    std::cerr << "Invalid arg: " << argv[1] << std::endl;
    return 1;
  }
  return 0;

  return 0;
}