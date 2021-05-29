#include "BobcatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
BobcatApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

BobcatApp::BobcatApp(InputParameters parameters) : MooseApp(parameters)
{
  BobcatApp::registerAll(_factory, _action_factory, _syntax);
}

BobcatApp::~BobcatApp() {}

void
BobcatApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"BobcatApp"});
  Registry::registerActionsTo(af, {"BobcatApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
BobcatApp::registerApps()
{
  registerApp(BobcatApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
BobcatApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  BobcatApp::registerAll(f, af, s);
}
extern "C" void
BobcatApp__registerApps()
{
  BobcatApp::registerApps();
}
