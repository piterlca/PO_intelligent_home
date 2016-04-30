/*
 * Model.cpp



 *
 *  Created on: Apr 30, 2016
 *      Author: piotr
 */
#define VERBOSITY 4

#if VERBOSITY >= 4
#include <iostream>
#endif

#include "../../Incl/Utils/Deserializers/ModelDeserializers/ModelCategoryDeserializer.hpp"
#include "../../Incl/Utils/Deserializers/ModelDeserializers/ModelDeserializer.hpp"
#include "../../Incl/Utils/Deserializers/ModelDeserializers/ModelIDDeserializer.hpp"
#include "../../Incl/Utils/Deserializers/ModelDeserializers/ModelLibDeserializer.hpp"
#include "../../Incl/Utils/SH_exceptions.hpp"
#include "../../Incl/Models/Dummy_Model.hpp"
#include "../../Incl/Smart_house_iface/Model.hpp"

using namespace SH_Exceptions;

namespace Smart_house{

Model*
Model::createModel(const string& serializedParams)
{
	ModelCategoryDeserializer catDes;

	ModelFactory* mf = ModelFactory::GetModelFactory(catDes.deserialize(serializedParams));

	Model* model = mf->produceModel(serializedParams);

	delete mf;

	ModelFactory::InitializeModel(model, serializedParams);

#if VERBOSITY >= 4
	std::cout << "Created model: \nID =  "<< model->ID <<
			"\ncategory = " << model->category <<
			"\nLib = "<< model->DeviceLibrary << std::endl;
#endif

	return model;
}

ModelFactory*
ModelFactory::GetModelFactory(const string& modelType)
{
	if("DummyTemp" == modelType)
		return new DummyModelFactory;

	else
		throw(new SH_Exceptions::DataTypeNotSupportedException(modelType));
}

void
ModelFactory::InitializeModel(Model* model, const string& serializedParams)
{
	ModelIDDeserializer idDes;
	ModelCategoryDeserializer catDes;
	ModelLibDeserializer libDes;

	model->ID = idDes.deserialize(serializedParams);
	model->category = catDes.deserialize(serializedParams);
	model->DeviceLibrary = libDes.deserialize((serializedParams));
}

};
