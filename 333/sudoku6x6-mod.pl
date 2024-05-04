sudoku(X1,X2,X3,X4,X5,X6,
X7,X8,X9,X10,X11,X12,
X13,X14,X15,X16,X17,X18,
X19,X20,X21,X22,X23,X24,
X25,X26,X27,X28,X29,X30,
X31,X32,X33,X34,X35,X36) :-

    Row1 = [X1, X2, X3, X4, X5, X6],
    Row2 = [X7, X8, X9, X10, X11, X12],
    Row3 = [X13, X14, X15, X16, X17, X18],
    Row4 = [X19, X20, X21, X22, X23, X24],
    Row5 = [X25, X26, X27, X28, X29, X30],
    Row6 = [X31, X32, X33, X34, X35, X36],

    Col1 = [X1, X7, X13, X19, X25, X31],
    Col2 = [X2, X8, X14, X20, X26, X32],
    Col3 = [X3, X9, X15, X21, X27, X33],
    Col4 = [X4, X10, X16, X22, X28, X34],
    Col5 = [X5, X11, X17, X23, X29, X35],
    Col6 = [X6, X12, X18, X24, X30, X36],

    Square1 = [X1, X2, X3, X7, X8, X9],
    Square2 = [X4, X5, X6, X10, X11, X12],
    Square3 = [X13, X14, X15, X19, X20, X21],
    Square4 = [X16, X17, X18, X22, X23, X24],
    Square5 = [X25, X26, X27, X31, X32, X33],
    Square6 = [X28, X29, X30, X34, X35, X36],

    Sets = [Row1, Row2, Row3, Row4, Row5, Row6
           Col1, Col2, Col3, Col4, Col5, Col6
           Square1, Square2, Square3, Square4, Square5, Square6],

    maplist(permutation([1,2,3,4,5,6]), Sets).