printf("\nlist starting and ending in Hole\n");
printf("--------------------------------\n");
Link node = createNodeWithNext(true, 0, 26, 6, NULL);
Link node2 = createNodeWithNext(false, 3, 16, 10, node);
Link node3 = createNodeWithNext(true, 0, 15, 1, node2);
Link node4 = createNodeWithNext(true, 0, 11, 4, node3);
Link node5 = createNodeWithNext(true, 0, 7, 4, node4);
Link node6 = createNodeWithNext(false, 17, 6, 1, node5);
Link head = createNodeWithNext(true, 1, 0, 6, node6);

printMemory(head);
printf("\n");
compaction(&head);
printMemory(head);
printf("--------------------------------\n");

printf("\nlist starting with process and ending in Hole\n");
printf("--------------------------------\n");
Link testNode = createNodeWithNext(true, 0, 26, 6, NULL);
Link testNode2 = createNodeWithNext(false, 3, 16, 10, testNode);
Link testNode3 = createNodeWithNext(true, 0, 7, 9, testNode2);
Link testNode4 = createNodeWithNext(false, 2, 6, 1, testNode3);
Link testHead = createNodeWithNext(false, 1, 0, 6, testNode4);

printMemory(testHead);
printf("\n");
compaction(&testHead);
printMemory(testHead);
printf("--------------------------------\n");

printf("\nOne process test\n");
printf("----------------------------------\n");
head = NULL;
push(&head, false, 1, 0, 10);
printMemory(head);
printf("\n");
compaction(&head);
printMemory(head);
printf("----------------------------------\n");


printf("\ntwo hole test\n");
printf("----------------------------------\n");
head = NULL;
push(&head, true, 0, 10, 12);
push(&head, true, 0, 0, 10);
printMemory(head);
printf("\n");
compaction(&head);
printMemory(head);
printf("----------------------------------\n");


printf("\nlist starting with hole test\n");
printf("----------------------------------\n");
head = NULL;
push(&head, true, 0, 47, 2);
push(&head, false, 5, 46, 1);
push(&head, false, 4, 37, 9);
push(&head, true, 0, 35, 2);
push(&head, true, 0, 34, 1);
push(&head, true, 0, 28, 6);
push(&head, false, 3, 18, 10);
push(&head, true, 0, 17, 1);
push(&head, false, 2, 16, 1);
push(&head, false, 1, 10, 6);
push(&head, true, 0, 0, 10);
printMemory(head);
printf("\n");
compaction(&head);
printMemory(head);
printf("----------------------------------\n");


printf("\nlist starting with process test\n");
printf("----------------------------------\n");
head = NULL;
push(&head, true, 0, 47, 2);
push(&head, false, 6, 46, 1);
push(&head, false, 5, 37, 9);
push(&head, true, 0, 35, 2);
push(&head, true, 0, 34, 1);
push(&head, true, 0, 28, 6);
push(&head, false, 4, 18, 10);
push(&head, true, 0, 17, 1);
push(&head, false, 3, 16, 1);
push(&head, false, 2, 10, 6);
push(&head, false, 1, 0, 10);
printMemory(head);
printf("\n");
compaction(&head);
printMemory(head);
printf("----------------------------------\n");

printf("\nmergeFreeBlocks TESTS BEGIN HERE\n");
printf("----------------------------------\n");
printf("empty list test\n");
head = NULL;
printMemory(head);
printf("\n");
mergeFreeBlocks(&head);
printMemory(head);
printf("----------------------------------\n");


printf("\ntwo process test\n");
printf("----------------------------------\n");
head = NULL;
push(&head, false, 2, 10, 12);
push(&head, false, 1, 0, 10);
printMemory(head);
printf("\n");
mergeFreeBlocks(&head);
printMemory(head);
printf("----------------------------------\n");

printf("\ntwo hole test\n");
printf("----------------------------------\n");
head = NULL;
push(&head, true, 0, 10, 12);
push(&head, true, 0, 0, 10);
printMemory(head);
printf("\n");
mergeFreeBlocks(&head);
printMemory(head);
printf("----------------------------------\n");


printf("\nlist starting with hole test\n");
printf("----------------------------------\n");
head = NULL;
push(&head, true, 0, 49, 4);
push(&head, true, 0, 47, 2);
push(&head, false, 5, 46, 1);
push(&head, false, 4, 37, 9);
push(&head, true, 0, 35, 2);
push(&head, true, 0, 34, 1);
push(&head, true, 0, 28, 6);
push(&head, false, 3, 18, 10);
push(&head, true, 0, 17, 1);
push(&head, false, 2, 16, 1);
push(&head, false, 1, 10, 6);
push(&head, true, 0, 0, 10);
printMemory(head);
printf("\n");
mergeFreeBlocks(&head);
printMemory(head);
printf("----------------------------------\n");


printf("\nlist starting with process test\n");
printf("----------------------------------\n");
head = NULL;
push(&head, true, 0, 49, 4);
push(&head, true, 0, 47, 2);
push(&head, false, 6, 46, 1);
push(&head, false, 5, 37, 9);
push(&head, true, 0, 35, 2);
push(&head, true, 0, 34, 1);
push(&head, true, 0, 28, 6);
push(&head, false, 4, 18, 10);
push(&head, true, 0, 17, 1);
push(&head, false, 3, 16, 1);
push(&head, false, 2, 10, 6);
push(&head, false, 1, 0, 10);
printMemory(head);
printf("\n");
mergeFreeBlocks(&head);
printMemory(head);
printf("----------------------------------\n");
