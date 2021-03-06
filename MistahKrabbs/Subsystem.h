#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

namespace Krabbs {

	class Subsystem {
		
	private:
		
	public:
		Subsystem();
		virtual ~Subsystem();
		
		virtual void init() = 0;
		virtual void update() = 0;
		virtual void disable() = 0;
	

	};
	
	namespace Command {
		enum DriveCommand {
			ANGLE_ALL_WHEELS,
			ROTATE_ROBOT
		};
	}
}
#endif
