#include <iostream>
#include <cassert>
#include "yaml-cpp/yaml.h"


static const char* yaml_string = R"(
#
type: leoquad
name: LeoQuad
version: v1.0

base2FootPosXY: [ 0.291, 0.1245 ]

# for simulation
simulation:
  jointPgain: [ 150.0, 100.0, 50.0,
                150.0, 100.0, 50.0,
                150.0, 100.0, 50.0,
                150.0, 100.0, 50.0 ]
  jointDgain: [ 15.0, 10.0, 5.0,
                15.0, 10.0, 5.0,
                15.0, 10.0, 5.0,
                15.0, 10.0, 5.0 ]

# for actual robot
actual:
  jointPgain: [ 110.0, 110.0, 110.0,
                110.0, 110.0, 110.0,
                110.0, 110.0, 110.0,
                110.0, 110.0, 110.0 ]

  jointDgain: [ 8.0, 8.0, 6.0,
                8.0, 8.0, 6.0,
                8.0, 8.0, 6.0,
                8.0, 8.0, 6.0 ]

# other parameters
param:
  - param1: 9.8
  - param2: "hello"
)";


typedef double SYSREAL;

class RobotConfig {
public:
  RobotConfig(const std::string& yaml) 
  {
    //_rootNode = YAML::LoadFile(yaml);
    _rootNode = YAML::Load(yaml);
  }
  RobotConfig(const YAML::Node& node)
  {
    _rootNode = node;
  }

  template<typename Key>
  const RobotConfig operator[](const Key& key) const
  {
    return RobotConfig(_rootNode[key]);
  }
  template<typename Key>
  RobotConfig operator[](const Key& key)
  {
    return RobotConfig(_rootNode[key]);
  }

  template<typename ValueType>
  const ValueType to() const
  {
    return _rootNode.as<ValueType>();
  }

  const std::string toString() const{
    return _rootNode.as<std::string>();
  }

  const double toDouble() const{
    return _rootNode.as<double>();
  }

  const double toInt32() const{
    return _rootNode.as<int32_t>();
  }

  const double toUInt32() const{
    return _rootNode.as<uint32_t>();
  }

  const double toReal() const{
    return _rootNode.as<SYSREAL>();
  }

  size_t size()
  {
    assert(_rootNode.IsSequence());
    if (_rootNode.IsSequence())
      return _rootNode.size();
    else
      return 0; // Not an array !!!
  }


private:
  YAML::Node _rootNode;
};

int main()
{
    //YAML::Node config = YAML::LoadFile("test.yaml");
    YAML::Node config = YAML::Load(yaml_string);
    if (config["type"]) {
        std::cout << "type = " << config["type"].as<std::string>() << std::endl;
    }
    if (config["simulation"] && config["simulation"]["jointPgain"]) {
        assert(config["simulation"]["jointPgain"].Type() == YAML::NodeType::Sequence);
        assert(config["simulation"]["jointPgain"].IsSequence());
        for (int i=0; i<config["simulation"]["jointPgain"].size(); i++) {
            std::cout << "kp[" << i << "] = " << config["simulation"]["jointPgain"][i].as<double>() << std::endl;
        }

    }

    RobotConfig conf(yaml_string);
    std::cout << "type = " << conf["type"].to<std::string>() << std::endl;
    std::cout << "name = " << conf["name"].toString() << std::endl;
    for (int i=0; i<conf["simulation"]["jointPgain"].size(); i++) {
      std::cout << "kp[" << i << "] = " << conf["simulation"]["jointPgain"][i].toReal() << std::endl;
    }

    return 0;
}