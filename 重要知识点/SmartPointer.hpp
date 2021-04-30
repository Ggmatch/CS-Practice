#pragma once

template <typename T>
class MySharedPtr
{
private:
    T *_ptr;
    size_t *_count;

public:
    MySharedPtr(T *ptr = nullptr) : _ptr(ptr)
    {
        if (_ptr)
        {
            _count = new size_t(1);
        }
        else
        {
            _count = new size_t(0);
        }
    }

    MySharedPtr(const MySharedPtr &ptr)
    {
        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;
    }

    MySharedPtr &operator=(const MySharedPtr &ptr)
    {
        if (this->_ptr == ptr._ptr)
        {
            // 赋值运算符右边与左边是指向同一内存的指针
            return *this;
        }

        if (this->_ptr)
        {
            // 对赋值运算符右边智能指针进行一次释放
            (*this->_count)--;
            if (this->_count == 0)
            {
                delete this->_ptr;
                delete this->_count;
            }
        }
        // 赋值运算符右边智能指针被左边的覆盖
        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;
        return *this;
    }

    T &operator*()
    {
        // 空指针会触发断言
        assert(this->_ptr != nullptr);
        return *(this->_ptr);
    }

    T *operator->()
    {
        assert(this->_ptr != nullptr);
        return this->_ptr;
    }

    ~MySharedPtr()
    {
        (*this->_count)--;
        if (*this->_count == 0)
        {
            delete this->_ptr;
            delete this->_count;
        }
    }

    size_t use_count()
    {
        return *this->_count;
    }
};