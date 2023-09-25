#ifndef LSTACK_H
#define LSTACK_H
#include <memory>
template <typename T>
class LStack{
    struct Link{
        std::shared_ptr<Link> m_spNext;
        T m_data;
    };
    std::shared_ptr<Link> m_spTop;
    int m_size = 0;
public:
    void pushBack(T data){
        // TODO
        Link old;
        old.m_data=data;

        std::shared_ptr<Link> temp = std::make_shared <Link>(old);
        if (m_spTop == nullptr) {
            m_spTop = temp;
        }
        else {
            temp->m_spNext = m_spTop;
            m_spTop = temp;
        }
        m_size+=1;
    }
    void pop(){
        // TODO
        m_spTop=(*m_spTop).m_spNext;
        m_size-=1;
    }

    T& top() const {
        // TODO
        return (*m_spTop).m_data;

    }
    int size() const {
        return m_size;
    }
};

#endif // LSTACK_H
