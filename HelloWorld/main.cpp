#include <iostream>
#include <string>
#include <vector>

namespace design_pattern {

class subject {
    std::vector<class observer *> observers_;
public:
    void attach(class observer * o) {
        observers_.push_back(o);
    }
    void notify();
};

class observer {
    class subject * subject_ = nullptr;
public:
    observer() = default;
    observer(class subject *s): subject_(s) { subject_->attach(this); }
    class subject * get_subject() { return subject_; }
    void set_subject(class subject *s) { subject_ = s; subject_->attach(this); }
    virtual void update() = 0;
};

void subject::notify() {
    for (class observer * o : observers_)
        o->update();
}

} //namespace

int main()
{
    class concrete_subject : public design_pattern::subject {
        std::string subject_state_ = "s";
    public:
        std::string const & get_state() const { return subject_state_; }
        void set_state(std::string const & state) {
            subject_state_ = state;
            notify();
        }
    };

    class concrete_observer : public design_pattern::observer {
        std::string subject_state_ = "o";
    public:
        using design_pattern::observer::observer;
        void update() override {
            //
            // Notified something dependent is changed, recaculate internal state
            //
            subject_state_ = static_cast<concrete_subject*>(get_subject())->get_state();
        }
        std::string const & get_state() const { return subject_state_; }
    };

    concrete_subject s;
    std::vector<concrete_observer> O;
    O.push_back(*(new concrete_observer(&s)));
    O.push_back(*(new concrete_observer(&s)));

    std::vector<concrete_observer*> R;
    R.push_back(new concrete_observer(&s));
    R.push_back(new concrete_observer(&s));

    s.set_state("notice ... ");
    std::cout << "S: " << s.get_state() << std::endl;
    for (concrete_observer & o : O) std::cout << "O: " <<  o.get_state() << std::endl;
    for (concrete_observer * r : R) std::cout << "R: " << r->get_state() << std::endl;
}
