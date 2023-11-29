// optional: enable FSM structure report in debugger
#define HFSM2_ENABLE_STRUCTURE_REPORT
#include "hfsm2/machine.hpp"

#include <iostream>
#include <string>

using namespace std;

#define PRINTCALL std::cout << __LINE__ << ": " << __FUNCTION__ << std::endl


typedef enum _ControlMode
{
    CTRL_NONE = 0,
    CTRL_TORQ_OFF = 1,
    CTRL_WALKREADY = 2,
    CTRL_GAIT = 3,
    CTRL_SIT_DOWN = 4,
    CTRL_SIT_UP = 5,
    CTRL_DHTEST = 6,
    CTRL_READYTOSTAND = 7,
    NUM_OF_CTRL_MODE
} ControlMode;

static const std::string controlModeName[NUM_OF_CTRL_MODE] =
{
    "None",
    "Torque Off",
    "Ready To Walk",
    "GAIT ENABLED",
    "Sit Down",
    "Sit Up",
    "D-H Tester",
    "Ready To Stand"
};

typedef enum _GaitType
{
    GAIT_NONE = 0,
    GAIT_WALK,
    GAIT_TROT,
    GAIT_FLYINGTROT,
    GAIT_BOUND,
    GAIT_PACE,
    GAIT_GALLOP,
    GAIT_STAIRTROT,
    GAIT_PRONK,
    NUM_OF_GAIT
} GaitType;

static const std::string gaitNames[NUM_OF_GAIT] = 
{
    "None",
    "Walk",
    "Trot",
    "Flying Trot",
    "Bound",
    "Pace",
    "Gallop",
    "Stair Trot",
    "Pronk"
};

class RobotData
{
public:
	
	int ctrlMode{0};
	int gaitType{0};
	bool moveDoneFlag{false};
	bool moveStopRequest{false};
	bool torqueOffRequest{false};
	bool faultFlag{false};


};


class QuadRobot
{
public:
	void InitSitUp()   { cout << "> InitSitUp()\n"; }
	void InitSitDown() { cout << "> InitSitDown()\n"; }
	void StartGait()   { cout << "> StartGait()\n"; }
	void StopGait()    { cout << "> StopGait()\n"; }
	void TorqueOff()   { cout << "> TorqueOff()\n"; }
};




//------------------------------------------------------------------------------

// data shared between FSM states and outside code
struct Context {
	QuadRobot& robot;
	RobotData& data;
	int ctrlCnt{0};

	Context(QuadRobot& r, RobotData& d) : robot(r), data(d) {}
};



QuadRobot _robot;
RobotData _data;



// convenience typedef
using M = hfsm2::MachineT<hfsm2::Config::ContextT<Context>>;

#if 0

// states need to be forward declared to be used in FSM struct declaration
struct On;
struct Red;
struct YellowDownwards;
struct YellowUpwards;
struct Green;
struct Off;

using FSM = M::PeerRoot<
				// sub-machine ..
				M::Composite<On,
					// .. with 4 sub-states
					Red,
					YellowDownwards,
					YellowUpwards,
					Green
				>,
				Off
			>;

#else

// alternatively, some macro magic can be invoked to simplify FSM structure declaration
#define S(s) struct s

// state machine structure
using FSM = M::PeerRoot<
				// sub-machine ..
				M::Composite<S(ENABLED),
					// .. with 4 sub-states
					S(INIT),
					S(SIT_UP),
					S(SIT_DOWN),
					S(FALL_BREAK),
					M::Composite<S(GAIT),
						// .. with 4 sub-states
						S(GAIT_READY),
						S(GAIT_START),
						S(GAIT_RUN),
						S(GAIT_STOP)
					>
				>,
				S(Fault)
			>;

#undef S

#endif

//------------------------------------------------------------------------------

static_assert(FSM::regionId<ENABLED>()			==  1, "");
static_assert(FSM::regionId<GAIT>()				==  2, "");

static_assert(FSM::stateId<ENABLED>()			==  1, "");
static_assert(FSM::stateId<INIT>()	     		==  2, "");
static_assert(FSM::stateId<SIT_UP>() 			==  3, "");
static_assert(FSM::stateId<SIT_DOWN>()	  		==  4, "");
static_assert(FSM::stateId<FALL_BREAK>()			==  5, "");
static_assert(FSM::stateId<GAIT>()			  	==  6, "");

////////////////////////////////////////////////////////////////////////////////

// events
struct SitUp {};
struct ReadyToWalk {};
struct Fall {};
struct StartGait {};
struct StopGait {};
struct TorqueOff {};



struct ENABLED : FSM::State
{
	void enter(Control& control) noexcept {
		cout << "> ENABLED::enter()\n";
	}

	void exit(Control& control) noexcept {
		cout << "> ENABLED::exit()\n";
	}
};

struct INIT : FSM::State
{
	using FSM::State::react;

	void enter(Control& control) noexcept {
		cout << "> INIT::enter()\n";
	}

	void react(const SitUp&, FullControl& control)
	{
		PRINTCALL;
		control.changeTo<SIT_UP>();
	}
};

struct SIT_UP : FSM::State
{
	void enter(Control& control) noexcept {
		cout << "> SIT_UP::enter()\n";
		control.context().robot.InitSitUp();
	}

	void update(FullControl& control) noexcept {
		control.changeTo<GAIT>();
	}
};

struct SIT_DOWN : FSM::State
{
	void enter(Control& control) noexcept {
		cout << "> SIT_DOWN::enter()\n";
		control.context().robot.InitSitDown();
	}

	void update(FullControl& control) noexcept {
		control.changeTo<INIT>();
	}
};

struct FALL_BREAK : FSM::State
{
	void enter(Control& control) noexcept {
		cout << "> FALL_BREAK::enter()\n";
	}

	void update(FullControl& control) noexcept {
		control.changeTo<INIT>();
	}
};

struct GAIT : FSM::State
{
	void enter(Control& control) noexcept {
		cout << "> GAIT::enter()\n";
	}

	void exit(Control& control) noexcept {
		cout << "> GAIT::exit()\n";
	}

	void update(FullControl& control) noexcept {
		cout << "> GAIT::update()\n";
	}
};

struct GAIT_READY : FSM::State
{
	using FSM::State::react;

	void enter(Control& control) noexcept {
		cout << "> GAIT_READY::enter()\n";
	}

	void react(const StartGait&, FullControl& control)
	{
		PRINTCALL;
		control.changeTo<GAIT_START>();
	}
};

struct GAIT_START : FSM::State
{
	void enter(Control& control) noexcept {
		cout << "> GAIT_START::enter()\n";
		control.context().robot.StartGait();
	}

	void update(FullControl& control) noexcept {
		control.context().ctrlCnt++;
		control.changeTo<GAIT_RUN>();
	}
};

struct GAIT_RUN : FSM::State
{
	using FSM::State::react;

	void enter(Control& control) noexcept {
		cout << "> GAIT_RUN::enter()\n";
	}

	void react(const StopGait&, FullControl& control)
	{
		PRINTCALL;
		control.changeTo<GAIT_STOP>();
	}
};

struct GAIT_STOP : FSM::State
{
	void enter(Control& control) noexcept {
		cout << "> GAIT_STOP::enter()\n";
		control.context().robot.StopGait();
	}

	void update(FullControl& control) noexcept {
		if (control.context().ctrlCnt > 3)
			control.changeTo<Fault>();
		else
			control.changeTo<GAIT_READY>();
	}
};

struct Fault : FSM::State
{
	void enter(Control& control) noexcept {
		cout << "> Fault::enter()\n";
		control.context().robot.TorqueOff();
	}
};







////////////////////////////////////////////////////////////////////////////////

int main() noexcept {
	Context context(_robot, _data);

	FSM::Instance machine{context};
	
	//machine.changeTo<SIT_UP>();
	machine.react(SitUp{});

	while (machine.isActive<Fault>() == false) {

		//if (machine.isActive<GAIT_READY>() == true)
			machine.react(StartGait{});
			machine.react(StopGait{});
			//machine.changeTo<GAIT_START>();

		machine.update();
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////
