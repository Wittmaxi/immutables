#pragma once
#include <stdarg.h>

template <typename T>
class IMU
{
  public:
    template <class... Ts>
    IMU(bool is_enabled, Ts... constructor)
    {
        enabled = is_enabled;

        contained = T(constructor...);

        //call the constructor of contained;
    }
    template <class... Ts>
    IMU(Ts... constructor)
    {
        contained = T(constructor...);
    }
    IMU(bool is_enabled, T object)
    {
        enabled = is_enabled;
        contained = object;
    }
    IMU(T object)
    {
        contained = object;
    }
    IMU(IMU<T> &other)
    {
        enabled = other.enabled;
        contained = other.contained;
    }
    void lock()
    {
        enabled = false;
    }
    void unlock()
    {
        enabled = true;
    }
    T operator*() const
    {
        return contained;
    }
    IMU<T> operator=(T rhs)
    {
        if (enabled)
        {
            contained = rhs;
            return *this;
        }
        IMU<T> ret;
        ret.enabled = true;
        ret.contained = rhs;
        return ret;
    }
    T &operator->()
    {
        if (enabled)
        {
            return contained;
        }
        T ret = contained;
        return ret;
    }
    T *get_raw_data()
    {
        return &contained;
    }

  private:
    bool enabled = true;
    T contained;
};