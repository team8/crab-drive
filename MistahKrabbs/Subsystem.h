#ifndef Subsyst_H
#define Subsyst_H

class Subsyst {
	
private:
	
public:
	Subsyst();
	virtual ~Subsyst();
	
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void disable() = 0;
};

#endif
