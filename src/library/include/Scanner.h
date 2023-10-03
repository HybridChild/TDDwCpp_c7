#pragma once

#include <string>

#include "HoldingService.h"
// TODO class HoldingService; need namespace wrappers
class DisplayListener;
class ScannerState;

class Scanner : public std::enable_shared_from_this<Scanner>
{
public:
    const static std::string INVENTORY_CARD_NUMBER;
    const static std::string MSG_INVALID_BARCODE;

    Scanner(DisplayListener*, service::HoldingService*);
    virtual ~Scanner();

	void Scan(const std::string& barcode);
	void PressDone();

    void ShowMessage(const std::string& message);
    std::shared_ptr<ScannerState> CurrentState();
    void SetCurrentState(std::shared_ptr<ScannerState> state);

    std::string BranchId();
    void SetBranchId(const std::string&);
    std::string PatronId();
    void SetPatronId(const std::string&);

    service::HoldingService* HoldingService();

private:
    DisplayListener* mDisplay;
    std::string mBranchId;
    std::string mPatronId;
    std::shared_ptr<ScannerState> mCurrentState;
    service::HoldingService* mHoldingService;

};
