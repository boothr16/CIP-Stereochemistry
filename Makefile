OBJS = main.o AtomNode.o ATOM_COMPARATOR.o Tetrahedral.o \
TrigonalProjection.o

cip : $(OBJS)
	g++ -o cip $(OBJS)

main.o : PRIORITY_TABLE.hpp Tetrahedral.hpp AtomNode.hpp \
TrigonalProjection.hpp

AtomNode.o : PRIORITY_TABLE.hpp

ATOM_COMPARATOR.o : AtomNode.hpp

Tetrahedral.o : AtomNode.hpp ATOM_COMPARATOR.hpp

TrigonalProjection.o : Tetrahedral.hpp

.PHONY : clean

clean :
	-rm cip $(OBJS) 