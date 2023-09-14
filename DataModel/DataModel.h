#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <map>
#include <string>
#include <vector>
#include "Utilities.h"

// #include "TTree.h"

#include "BStore.h"
#include "Logging.h"
#include "Store.h"

#include "G4RunManager.hh"
#include "G4UImanager.hh"

#include "WCSimTuningParameters.hh"
#include "WCSimDetectorConstruction.hh"
#include "WCSimPrimaryGeneratorAction.hh"
#include "WCSimPhysicsListFactory.hh"
#include "WCSimRunAction.hh"
#include "WCSimRandomParameters.hh"
#include "WCSimEventAction.hh"
#include "WCSimStackingAction.hh"
#include "WCSimSteppingAction.hh"

/**
 * \class DataModel
 *
 * This class Is a transient data model class for your Tools within the ToolChain. If Tools need to comunicate
 * they pass all data objects through the data model. There fore inter tool data objects should be deffined in
 * this class.
 *
 *
 * $Author: B.Richards $
 * $Date: 2019/05/26 18:34:00 $
 *
 */

class DataModel {

	public:

		DataModel();  ///< Simple constructor

		// TTree* GetTTree(std::string name);
		// void AddTTree(std::string name,TTree *tree);
		// void DeleteTTree(std::string name,TTree *tree);

		Logging* Log;  ///< Log class pointer for use in Tools, it can be used to send messages which can have
		               ///< multiple error levels and destination end points

		Store vars;  ///< This Store can be used for any variables. It is an inefficent ascii based storage
		             ///< and command line arguments will be placed in here along with ToolChain variables
		BStore
		    CStore;  ///< This is a more efficent binary Store that can be used to store a dynamic set of
		             ///< inter Tool variables, very useful for constants and and flags hence the name CStore
		std::map<std::string, BStore*>
		    Stores;  ///< This is a map of named BStore pointers which can be deffined to hold a nammed
		             ///< collection of any type of BStore. It is usefull to store data collections that needs
		             ///< subdividing into differnt stores.

	//Geant4 essentials
  //std::unique_ptr<G4RunManager> m_p_g4_run_manager;
	G4UImanager* m_p_UI;

	//WCSim legacy
	std::unique_ptr<WCSimTuningParameters> m_p_g4_tuning_pars;
	std::unique_ptr<WCSimDetectorConstruction> m_p_wcsim_detector_construction;
	std::unique_ptr<WCSimPrimaryGeneratorAction> m_p_wcsim_primary_generator_action;
	std::unique_ptr<WCSimPhysicsListFactory> m_p_wcsim_physics_list_factory;
	std::unique_ptr<WCSimRunAction> m_p_wcsim_run_action;
	std::unique_ptr<WCSimRandomParameters> m_p_wcsim_random_parameters;
	std::unique_ptr<WCSimEventAction> m_p_wcsim_event_action;
	std::unique_ptr<WCSimStackingAction> m_p_wcsim_stacking_action;
	std::unique_ptr<WCSimSteppingAction> m_p_wcsim_stepping_action;
	std::string m_wcsim_mac_job_opt_filename;

	unsigned long m_current_event; ///< Current event number

	private:

		// std::map<std::string,TTree*> m_trees;
};

#endif
