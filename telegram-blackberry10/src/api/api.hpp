/*
 * api.hpp
 *
 *  Created on: 6. 12. 2014.
 *      Author: Alfis
 */

#ifndef API_HPP_
#define API_HPP_

#include "apiRegauth.hpp"
#include <bb/cascades/CustomControl>

class API: public APIRegAuth, public bb::cascades::CustomControl{
    Q_OBJECT

};



#endif /* API_HPP_ */
