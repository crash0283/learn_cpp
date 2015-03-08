/*
 * CreatingParticles.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: chrisrasch
 */

#include "CreatingParticles.h"
#include <stdlib.h>
#include <math.h>



namespace cmr {

CreatingParticles::CreatingParticles(): m_x(0), m_y(0){

	init();
}

CreatingParticles::~CreatingParticles() {
	// TODO Auto-generated destructor stub
}

void CreatingParticles::init() {

	m_x = 0;
	m_y = 0;

	m_direction = (2 * M_PI * rand())/RAND_MAX;
	m_speed = (0.04 * rand())/RAND_MAX;

	m_speed *= m_speed;
}

void CreatingParticles::update(int interval) {

	m_direction += interval * 0.0002;

	double x_speed = m_speed * cos(m_direction);
	double y_speed = m_speed * sin(m_direction);

	m_x += x_speed * interval;
	m_y += y_speed * interval;

	if(m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
		init();
	}

	if(rand() < RAND_MAX / 100) {
		init();
	}

}

} /* namespace cmr */
