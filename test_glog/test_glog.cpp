#include <glog/logging.h>

int main(int argc, char *argv[]) {
  google::InitGoogleLogging(argv[0]);

  // gflags library를 이용할 경우 아래와 같이 command line flag option을 변경해
  // 주어야 한다. (빌드시에도 gflag library가 linking되어야 함)
  // google::ParseCommandLineFlags(&argc, &argv, true);

  // default 설정 시, INFO, WARNING 레벨은 로그 파일에만 출력됨
  LOG(INFO) << "INFO 레벨의 로그";
  LOG(WARNING) << "WARNING 레벨의 로그";

  // default 설정 시, ERROR 레벨 이상부터 stderr 로 출력된다.
  LOG(ERROR) << "ERROR 레벨의 로그";

  // FATAL의 경우, Stack trace를 출력하고 프로그램을 종료시킨다.
  LOG(FATAL) << "FATAL 레벨의 로그";

  return 0;
}