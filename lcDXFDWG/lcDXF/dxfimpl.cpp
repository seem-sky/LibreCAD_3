#include "dxfimpl.h"

DXFimpl::DXFimpl(lc::StorageManager_SPtr s, lc::Document* d) {
    _storageManager = s;
    _document = d;
}


void DXFimpl::addLine(const DRW_Line& data) {
    // Create a cross at position 0,0
    auto layer = _storageManager->layerByName("0");
    auto builder = std::make_shared<lc::operation::Builder>(_document);
    builder->append(std::make_shared<lc::Line>(lc::geo::Coordinate(
                                                   data.basePoint.x,
                                                   data.basePoint.y),
                                               lc::geo::Coordinate(
                                                   data.secPoint.x,
                                                   data.secPoint.y),
                                               layer)).push();
    builder->execute();
}

void DXFimpl::addCircle(const DRW_Circle& data) {
    auto layer = _storageManager->layerByName("0");
    auto builder = std::make_shared<lc::operation::Builder>(_document);
    builder->append(std::make_shared<lc::Circle>(lc::geo::Coordinate(
                                                   data.basePoint.x,
                                                   data.basePoint.y),
                                               data.radious,
                                               layer)).push();
    builder->execute();
}

lc::Document* DXFimpl::document() {
    return _document;
}

lc::StorageManager_SPtr DXFimpl::storageManager() {
    return _storageManager;
}