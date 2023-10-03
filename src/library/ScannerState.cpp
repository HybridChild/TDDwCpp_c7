#include "ScannerState.h"

#include "HoldingService.h"

using namespace std;

void ScannerState::ShowMessage(const string& message)
{
    mScanner.lock()->ShowMessage(message);
}

string ScannerState::BranchId() const
{
    return mScanner.lock()->BranchId();
}

void ScannerState::SetBranchId(const string& id)
{
    mScanner.lock()->SetBranchId(id);
}

string ScannerState::PatronId() const
{
    return mScanner.lock()->PatronId();
}

void ScannerState::SetPatronId(const string& id)
{
    mScanner.lock()->SetPatronId(id);
}

service::HoldingService* ScannerState::HoldingService() const
{
    return mScanner.lock()->HoldingService();
}
