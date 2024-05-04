% Main predicate, calles other predicates
sudoku(X1,X2,X3,X4,X5,X6,
		X7,X8,X9,X10,X11,X12,
		X13,X14,X15,X16,X17,X18,
		X19,X20,X21,X22,X23,X24,
		X25,X26,X27,X28,X29,X30,
		X31,X32,X33,X34,X35,X36) :-
	solved(X1,X2,X3,X4,X5,X6,
			X7,X8,X9,X10,X11,X12,
			X13,X14,X15,X16,X17,X18,
			X19,X20,X21,X22,X23,X24,
			X25,X26,X27,X28,X29,X30,
			X31,X32,X33,X34,X35,X36),
	printsudoku(X1,X2,X3,X4,X5,X6),
	printsudoku(X7,X8,X9,X10,X11,X12),
	printsudoku(X13,X14,X15,X16,X17,X18),
	printsudoku(X19,X20,X21,X22,X23,X24),
	printsudoku(X25,X26,X27,X28,X29,X30),
	printsudoku(X31,X32,X33,X34,X35,X36).

% Helps to print the values
printsudoku(A, B, C, D, E, F) :- write(' '), write(A), write('  '), write(B), write('  '), write(C),
write('  '), write(D), write('  '), write(E), write('  '), write(F), nl.

% Solves the puzzle by making sure the values are all different
solved(R1C1, R1C2, R1C3, R1C4, R1C5, R1C6
		R2C1, R2C2, R2C3, R2C4, R2C5, R2C6
		R3C1, R3C2, R3C3, R3C4, R3C5, R3C6,
		R4C1, R4C2, R4C3, R4C4, R4C5, R4C6,
		R5C1, R5C2, R5C3, R5C4, R5C5, R5C6,
		R6C1, R6C2, R6C3, R6C4, R6C5, R6C6):-
	different(R1C1, R1C2, R1C3, R1C4, R1C5, R1C6), % First row
	different(R2C1, R2C2, R2C3, R2C4, R2C5, R2C6), % Second row
	different(R3C1, R3C2, R3C3, R3C4, R3C5, R3C6), % Third row
	different(R4C1, R4C2, R4C3, R4C4, R4C5, R4C6), % Fourth row
	different(R5C1, R5C2, R5C3, R5C4, R5C5, R5C6), % Fifth row
	different(R6C1, R6C2, R6C3, R6C4, R6C5, R6C6), % Sixth row
	
	different(R1C1, R2C1, R3C1, R4C1, R5C1, R6C1), % First column
	different(R1C2, R2C2, R3C2, R4C2, R5C2, R6C2), % Second column
	different(R1C3, R2C3, R3C3, R4C3, R5C3, R6C3), % Third column
	different(R1C4, R2C4, R3C4, R4C4, R5C4, R6C4), % Fourth column
	different(R1C5, R2C5, R3C5, R4C5, R5C5, R6C5), % Fifth column
	different(R1C6, R2C6, R3C6, R4C6, R5C6, R6C6), % Sixth column
	
	different(R1C1, R1C2, R1C3, R2C1, R2C2, R2C3, R3C1, R3C2, R3C3), % Top Left block
	different(R1C4, R1C5, R1C6, R2C4, R2C5, R2C6, R3C4, R3C5, R3C6), % Top Right block
	different(R4C1, R4C2, R4C3, R5C1, R5C2, R5C3, R6C1, R6C2, R6C3), % Bottom Left block
	different(R4C4, R4C5, R4C6, R5C4, R5C5, R5C6, R6C4, R6C5, R6C6). % Bottom RIght block


% Determine if each square in either a row, column, or block are
% different
different(A, B, C, D, E, F) :- num(A), num(B), num(C), num(D), num(E), num(F),
A\=B, A\=C, A\=D, A\=E, A\=F,
B\=C, B\=D, B\=E, B\=F,
C\=D, C\=E, C\=F,
D\=E, D\=F,
E\=F.

% Initialize numbers
num(1). num(2). num(3). num(4). num(5). num(6).