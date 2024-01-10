runAll: runMapTest runSetTest runListTest runStackTest

buildAll: buildMapTest buildSetTest buildListTest buildStackTest

buildMapTest:
	gcc -g -Wall tests/hashMapTests.c HashMap.c LinkedList.c DoublyNode.c -o mapTest

buildSetTest:
	gcc -g -Wall tests/hashSetTests.c HashSet.c LinkedList.c DoublyNode.c -o setTest

buildListTest:
	gcc -g -Wall tests/linkedListTests.c LinkedList.c DoublyNode.c -o listTest

buildStackTest:
	gcc -g -Wall tests/stackTests.c Stack.c Node.c -o stackTest

runMapTest: buildMapTest
	./mapTest

runSetTest: buildSetTest
	./setTest

runListTest: buildListTest
	./listTest

runStackTest: buildStackTest
	./stackTest

clean:
	rm -f prog mapTest setTest listTest stackTest