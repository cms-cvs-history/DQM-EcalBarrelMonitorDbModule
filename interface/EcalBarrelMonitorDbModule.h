#ifndef EcalBarrelMonitorDbModule_H
#define EcalBarrelMonitorDbModule_H

/*
 * \file EcalBarrelMonitorDbModule.h
 *
 * $Date: 2006/06/07 10:59:25 $
 * $Revision: 1.4 $
 * \author G. Della Ricca
 *
*/

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include <FWCore/Framework/interface/EDAnalyzer.h>
#include <FWCore/Framework/interface/Event.h>
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"
#include "DQMServices/Daemon/interface/MonitorDaemon.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include <DQM/EcalBarrelMonitorDbModule/interface/MonitorElementsDb.h>

#include <string>

class EcalBarrelMonitorDbModule: public edm::EDAnalyzer{

 public:

  /// Constructor
  EcalBarrelMonitorDbModule( const edm::ParameterSet& ps );

  /// Destructor
  virtual ~EcalBarrelMonitorDbModule();

 protected:

  /// Analyze
  void analyze( const edm::Event& e, const edm::EventSetup& c );

  // BeginJob
  void beginJob( const edm::EventSetup& c );

  // EndJob
  void endJob( void );

 private:
  
  int icycle_;
 
  bool enableMonitorDaemon_;

  DaqMonitorBEInterface* dbe_;

  std::string htmlDir_;

  std::string xmlFile_;

  MonitorElementsDb* ME_Db_;

  unsigned int sleepTime_;

  coral::ISessionProxy* session_;

};

#endif