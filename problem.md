`error: invalid use of non-static member function ‘void StockOer::closeStockMarket()’`
个错误表明你正在尝试使用非静态成员函数作为函数指针，并将其赋值给 Eventhandler 的 update 成员。要解决这个问题，你需要将非静态成员函数改为静态成员函数，或者使用一个具有实例对象的普通函数来代替。

