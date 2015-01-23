#include "TreeWidgetFactory.h"

#include "Model.h"
#include "TreeNavigationView.h"

TreeWidgetFactory::TreeWidgetFactory(Model *model, StateMachine *stateMachine) :
    model(model),
    stateMachine(stateMachine)
{
    setDisplayName(tr("Coverage"));
    setPriority(110);
    setId(Core::Id("Coverage"));
}

Core::NavigationView TreeWidgetFactory::createWidget()
{
    Core::NavigationView n;
    TreeNavigationView *navigationView = new TreeNavigationView(model, stateMachine);
    n.widget = navigationView;
    return n;
}
