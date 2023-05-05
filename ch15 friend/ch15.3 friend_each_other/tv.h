#ifndef TV_H_
#define TV_H_

/*
前向声名：
解决值类型的对象字节大小不确定
A a; // 栈区

*/
class Tv; // forward declaration

class Remote {
    public:
        enum {Off, On};
        enum {MinVal, MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};
        enum {Buzz = 99};
    private:
        int mode;
    public:
        Remote(int m = TV) : mode(m) {}
        friend class Tv;
        bool volup(Tv & t);
        bool voldown(Tv & t);
        void onoff(Tv & t);
        void chanup(Tv & t);
        void chandown(Tv & t);
        void set_chan(Tv & t, int c);
        void set_mode(Tv & t);
        void set_input(Tv & t);
        void buzz();

};

class Tv {
    public:
        enum {Off, On};
        enum {MinVal, MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};
        friend class Remote;
        Tv(int s = Off, int mc = 125) : state(s), volume(5),maxchannel(mc),channel(2),mode(Cable),input(TV) {}
        void onoff() {state = (state == On) ? Off : On;}
        bool ison() const {return state == On;}
        bool volup();
        bool voldown();
        void chanup();
        void chandown();
        void set_mode() {mode = (mode == Antenna) ? Cable : Antenna;}
        void set_input(){input = (input == TV) ? DVD : TV;}
        void settings() const;
        void buzz(Remote & r);
    private:
        int state;
        int volume;
        int maxchannel;
        int channel;
        int mode;
        int input;
};


#endif