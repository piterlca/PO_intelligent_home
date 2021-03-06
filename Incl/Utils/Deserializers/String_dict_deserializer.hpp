/*
 * String_dict_deserializer.hpp
 *
 *  Created on: Apr 15, 2016
 *      Author: piotr
 */

#ifndef UTILS_STRING_DICT_DESERIALIZER_HPP_
#define UTILS_STRING_DICT_DESERIALIZER_HPP_

#include <string>

#include "../../../Incl/Smart_house_iface/Adapter_param.hpp"

using std::string;

namespace Utils{

class String_dict_deserializer{
public:
	Smart_house::Adapter_param deserialize(const string& serialized_data);

private:
	static const unsigned int STRING_EMPTY = 0;
};

}



#endif /* UTILS_STRING_DICT_DESERIALIZER_HPP_ */
