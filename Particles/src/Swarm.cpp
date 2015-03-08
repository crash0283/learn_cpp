/*
 * Swarm.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: chrisrasch
 */

#include "Swarm.h"

namespace cmr {

Swarm::Swarm(): lastTime(0) {
	m_pParticles = new CreatingParticles[NPARTICLES];
}

Swarm::~Swarm() {
	delete[] m_pParticles;
}

void Swarm::update(int elapsed) {

	int interval = elapsed - lastTime;

	for (int i = 0; i < Swarm::NPARTICLES; i++) {

		m_pParticles[i].update(interval);

	}

	lastTime = elapsed;

}
} /* namespace cmr */
