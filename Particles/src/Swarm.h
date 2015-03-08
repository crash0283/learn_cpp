/*
 * Swarm.h
 *
 *  Created on: Mar 6, 2015
 *      Author: chrisrasch
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "CreatingParticles.h"

namespace cmr {

class Swarm {
public:
	const static int NPARTICLES = 5000;
private:
	CreatingParticles *m_pParticles;
	int lastTime;
public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);

	const CreatingParticles *const getParticles() {
		return m_pParticles;
	}
};

} /* namespace cmr */

#endif /* SWARM_H_ */
