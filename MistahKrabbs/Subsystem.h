#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

class Subsystem {
private:
	
public:
	Subsystem();
	virtual Subsystem();
	
	virtual void update() = 0;
	virtual void init() = 0;
	virtual void disable() = 0;
	
};


#endif
