#include <cmath> // For std::cos, std::sin, std::acos, std::abs, std::sqrt
#include <iostream>
#include <limits> // For std::numeric_limits

// 쿼터니언 구조체 (간단하게 정의)
struct Quaternion
{
    double w, x, y, z;

    // 항등 쿼터니언
    static Quaternion Identity()
    {
        return {1.0, 0.0, 0.0, 0.0};
    }

    // 쿼터니언 정규화
    void normalize()
    {
        double magnitude = std::sqrt(w * w + x * x + y * y + z * z);
        if (magnitude > std::numeric_limits<double>::epsilon())
        { // 0으로 나누는 것 방지
            w /= magnitude;
            x /= magnitude;
            y /= magnitude;
            z /= magnitude;
        }
        else
        {
            // 정규화할 수 없는 경우 (0 쿼터니언), 항등 쿼터니언으로 설정하거나 오류 처리
            *this = Identity();
        }
    }

    // 쿼터니언 내적 (Dot Product)
    double dot(const Quaternion &other) const
    {
        return w * other.w + x * other.x + y * other.y + z * other.z;
    }

    // 쿼터니언 스칼라 곱셈
    Quaternion operator*(double scalar) const
    {
        return {w * scalar, x * scalar, y * scalar, z * scalar};
    }

    // 쿼터니언 덧셈
    Quaternion operator+(const Quaternion &other) const
    {
        return {w + other.w, x + other.x, y + other.y, z + other.z};
    }

    // 쿼터니언 음수 (방향 반전)
    Quaternion operator-() const
    {
        return {-w, -x, -y, -z};
    }
};

// -------------------------------------------------------------------------
// 1. 선형 보간 (Lerp)
// -------------------------------------------------------------------------
// 두 쿼터니언 q1과 q2 사이를 t (0.0 ~ 1.0) 비율로 선형 보간합니다.
// 결과는 정규화되지 않을 수 있으므로, 사용 후 normalize()를 호출해야 합니다.
Quaternion lerp(const Quaternion &q1, const Quaternion &q2, double t)
{
    Quaternion result = {
        q1.w * (1.0 - t) + q2.w * t,
        q1.x * (1.0 - t) + q2.x * t,
        q1.y * (1.0 - t) + q2.y * t,
        q1.z * (1.0 - t) + q2.z * t};
    result.normalize(); // Lerp 후에는 반드시 정규화
    return result;
}

// -------------------------------------------------------------------------
// 2. 구형 선형 보간 (Slerp)
// -------------------------------------------------------------------------
// 두 쿼터니언 q1과 q2 사이를 t (0.0 ~ 1.0) 비율로 구형 선형 보간합니다.
// 결과는 정규화된 쿼터니언입니다.
Quaternion slerp(const Quaternion &q1, const Quaternion &q2, double t)
{
    // 쿼터니언은 정규화되어 있다고 가정합니다.
    // 만약 정규화되지 않은 쿼터니언이 들어올 가능성이 있다면, 여기서 정규화를 수행해야 합니다.
    // Quaternion q1_norm = q1; q1_norm.normalize();
    // Quaternion q2_norm = q2; q2_norm.normalize();

    double dot = q1.dot(q2);

    // 내적이 음수인 경우, q2의 부호를 뒤집습니다.
    // 이렇게 하면 Slerp가 항상 짧은 호를 따라 보간하게 됩니다.
    Quaternion q2_adjusted = q2;
    if (dot < 0.0)
    {
        q2_adjusted = -q2;
        dot = -dot; // 내적도 양수로 만듭니다.
    }

    // 두 쿼터니언이 거의 같은 경우 (각도가 매우 작음)
    // 선형 보간으로 대체하여 부동 소수점 오차를 줄입니다.
    const double DOT_THRESHOLD = 0.9995;
    if (dot > DOT_THRESHOLD)
    {
        // Linear interpolate and normalize
        return lerp(q1, q2_adjusted, t);
    }

    double theta = std::acos(dot); // 두 쿼터니언 사이의 각도 (라디안)
    double sinTheta = std::sin(theta);

    // sinTheta가 0에 가까우면 나누기 오류가 발생할 수 있으므로 처리
    if (std::abs(sinTheta) < std::numeric_limits<double>::epsilon())
    {
        return q1; // 거의 같은 쿼터니언이므로 q1 반환 (또는 q2)
    }

    double ratioA = std::sin((1.0 - t) * theta) / sinTheta;
    double ratioB = std::sin(t * theta) / sinTheta;

    return (q1 * ratioA) + (q2_adjusted * ratioB);
}

// 결과를 확인하기 위한 간단한 출력 함수 (오일러 각 변환은 위에서 다루었으므로 생략)
void printQuaternion(const std::string &name, const Quaternion &q)
{
    std::cout << name << ": w=" << q.w << ", x=" << q.x << ", y=" << q.y << ", z=" << q.z << std::endl;
}

int main()
{
    // 시작 쿼터니언 (항등 쿼터니언)
    Quaternion q_start = Quaternion::Identity();

    // 목표 쿼터니언 (예: Z축으로 90도 회전)
    // 쿼터니언으로 변환: cos(45), 0, 0, sin(45)
    Quaternion q_end = {std::cos(M_PI / 4.0), 0.0, 0.0, std::sin(M_PI / 4.0)};
    q_end.normalize(); // 목표 쿼터니언도 정규화되어 있어야 합니다.

    std::cout << "Starting Quaternion:" << std::endl;
    printQuaternion("q_start", q_start);
    std::cout << "Ending Quaternion:" << std::endl;
    printQuaternion("q_end", q_end);
    std::cout << std::endl;

    std::cout << "--- Lerp Examples ---" << std::endl;
    for (double t = 0.0; t <= 1.0; t += 0.25)
    {
        Quaternion q_lerped = lerp(q_start, q_end, t);
        std::cout << "Lerp at t=" << t << std::endl;
        printQuaternion("  q_lerped", q_lerped);
    }
    std::cout << std::endl;

    std::cout << "--- Slerp Examples ---" << std::endl;
    for (double t = 0.0; t <= 1.0; t += 0.25)
    {
        Quaternion q_slerped = slerp(q_start, q_end, t);
        std::cout << "Slerp at t=" << t << std::endl;
        printQuaternion("  q_slerped", q_slerped);
    }
    std::cout << std::endl;

    // Slerp의 단거리 경로 테스트
    Quaternion q_test1 = {1.0, 0.0, 0.0, 0.0}; // Identity
    Quaternion q_test2 = {0.0, 0.0, 0.0, 1.0}; // 180도 Z축 회전 (0,0,0,1)

    std::cout << "--- Slerp Shortest Path Test ---" << std::endl;
    printQuaternion("q_test1", q_test1);
    printQuaternion("q_test2", q_test2);
    // Slerp(q_test1, q_test2, 0.5) 는 X축 90도 회전 쿼터니언이 아닌 Y축 90도 회전 쿼터니언을 반환할 수 있습니다.
    // 이는 내적이 음수일 때 q2를 뒤집어주는 로직 때문에 발생하며,
    // Slerp가 항상 두 쿼터니언 사이의 '가장 짧은' 경로를 택한다는 것을 보여줍니다.
    // 즉, 180도 회전을 직접 보간하기보다, 방향이 반대인 쿼터니언을 이용해 더 짧은 경로를 찾는 것입니다.
    Quaternion q_slerp_test = slerp(q_test1, q_test2, 0.5);
    printQuaternion("  slerp(q_test1, q_test2, 0.5)", q_slerp_test);
    std::cout << std::endl;
    // 위에 주석처리된 부분은 Slerp의 동작 방식에 대한 중요한 시사점을 보여줍니다.
    // (1,0,0,0)과 (0,0,0,1)은 서로 180도 차이나는 쿼터니언입니다.
    // Slerp는 이 두 쿼터니언 중 어떤 것을 선택하든 동일한 회전을 나타내는 다른 쿼터니언이 존재한다는 것을 고려합니다.
    // 예를 들어 (0,0,0,1)과 (-0,-0,-0,-1)은 같은 회전을 나타냅니다.
    // Slerp는 항상 가장 짧은 경로를 선택하기 위해 필요하다면 한 쿼터니언의 부호를 뒤집습니다.
    // q_test1.dot(q_test2) = 0 이므로 theta = M_PI / 2.0 (90도)
    // slerp(q_test1, q_test2, 0.5)는 실제 90도 회전을 의미합니다.
    // 이 경우 Z축 90도 회전과 X축 90도 회전 사이의 Slerp가 아닌,
    // (1,0,0,0)과 (0,0,0,1)을 잇는 가장 짧은 구형 호를 따라갑니다.
    // 이는 Slerp의 중요한 특징 중 하나입니다.

    // Gimbal Lock과 무관하게 Slerp는 항상 가장 짧은 경로를 찾아줍니다.
    Quaternion q_a = {1.0, 0.0, 0.0, 0.0};
    Quaternion q_b = {-1.0, 0.0, 0.0, 0.0}; // Identity와 같은 회전 (180도 다른 쿼터니언)
    std::cout << "--- Slerp 180 Degree Ambiguity Test ---" << std::endl;
    printQuaternion("q_a", q_a);
    printQuaternion("q_b", q_b); // 실제로는 q_a와 동일한 회전
    // Slerp는 q_b의 부호를 뒤집어 q_a와 더 가까운 쿼터니언으로 만든 후 보간합니다.
    // 따라서 결과는 q_a 또는 q_b에 매우 가까운 값이 나옵니다.
    Quaternion q_slerp_ambiguity = slerp(q_a, q_b, 0.5);
    printQuaternion("  slerp(q_a, q_b, 0.5)", q_slerp_ambiguity); // q_a와 거의 같음
    std::cout << std::endl;

    return 0;
}