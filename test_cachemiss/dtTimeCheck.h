/*!
\file       dtTimeCheck.h
\brief      Elapsed time Checker for Algorithm or loop, uint sec/msec/usec
\author     Dong-hyun Lee, phenom8305@gmail.com
\author     Who is next author?
\date       2018. 05. 28
\version    1.0.0
\copyright  (c) Dong-hyun Lee All rights reserved.
\warning    Do Not delete this comment for document history! This is minimal manners!
*/

#ifndef REALROBOT_UTILS_DTTIMECHECK_H
#define REALROBOT_UTILS_DTTIMECHECK_H

#if defined(_WIN32)
#if defined(_WIN64)
// define something for Windows (64-bit only)
#else
// define something for Windows (32-bit only)
#endif /* defined(_WIN64) */
// define something for Windows (32-bit or 64-bit)
#define NOMINMAX
#include <Windows.h>
#elif defined(__linux__)
#include <time.h>
#elif defined(ARDUINO)
#include <Arduino.h>
#endif

#if defined(_WIN32)
class dtTimeCheck
{
public:
    dtTimeCheck();
    ~dtTimeCheck();

    /*! Start Time Check */
    void Start(void);

    /*! Stop Time Check */
    int Stop();

    void Reset(void);

    double GetElapsedTime_sec(void);

    double GetElapsedTime_msec(void);

    double GetElapsedTime_usec();

private:
    bool bStart;
    double elapsedTime_msec;
    double elapsedTime_usec;
    LARGE_INTEGER freq;
    LARGE_INTEGER startTime;
    LARGE_INTEGER endTime;
};

#elif defined(__linux__)
class dtTimeCheck
{
public:
    dtTimeCheck();
    ~dtTimeCheck();

    /*! Start Time Check */
    void Start(void);

    /*! Stop Time Check */
    int Stop();

    void Reset(void);
    double GetElapsedTime_sec(void);
    double GetElapsedTime_msec(void);
    double GetElapsedTime_usec(void);
    long GetElapsedTime_nsec(void);

private:
    bool bStart;
    double elapsedTime_msec;
    double elapsedTime_usec;
    long elapsedTime_nsec;
    struct timespec startTime;
    struct timespec endTime;
};

#elif defined(ARDUINO)
class dtTimeCheck
{
public:
    dtTimeCheck();
    ~dtTimeCheck();

    /*! Start Time Check */
    void Start(void);
    /*! Stop Time Check */
    int Stop();

    void Reset(void);

    double GetElapsedTime_sec(void);

    double GetElapsedTime_msec(void);

    double GetElapsedTime_usec();

private:
    bool bStart;
    double elapsedTime_msec;
    double elapsedTime_usec;
    uint32_t startTime;
    uint32_t endTime;
};
#endif

#endif /* DH_TIME_CHECK_H */
