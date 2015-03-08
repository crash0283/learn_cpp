/*
 * CreatingParticles.h
 *
 *  Created on: Mar 6, 2015
 *      Author: chrisrasch
 */

#ifndef CREATINGPARTICLES_H_
#define CREATINGPARTICLES_H_

namespace cmr {

class CreatingParticles {
public:

	double m_x;
	double m_y;

	double m_speed;
	double m_direction;

public:
	CreatingParticles();
	virtual ~CreatingParticles();
	void update(int interval);
	void init();
};

} /* namespace cmr */

#endif /* CREATINGPARTICLES_H_ */
