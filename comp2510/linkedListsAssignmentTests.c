int main() {
    printf("COMPACTION TESTS BEGIN HERE\n");
    printf("empty list test\n");
    Node head = NULL;
    printMemory(head);
    printf("\n");
    compaction(&head);
    printMemory(head);

    printf("\nOne process test\n");
    head = NULL;
    push(&head, false, 1, 0, 10);
    printMemory(head);
    printf("\n");
    compaction(&head);
    printMemory(head);

    printf("\ntwo process test\n");
    head = NULL;
    push(&head, false, 2, 10, 12);
    push(&head, false, 1, 0, 10);
    printMemory(head);
    printf("\n");
    compaction(&head);
    printMemory(head);

    printf("\nOne hole test\n");
    head = NULL;
    push(&head, true, 0, 0, 10);
    printMemory(head);
    printf("\n");
    compaction(&head);
    printMemory(head);

    printf("\ntwo hole test\n");
    head = NULL;
    push(&head, true, 0, 10, 12);
    push(&head, true, 0, 0, 10);
    printMemory(head);
    printf("\n");
    compaction(&head);
    printMemory(head);

    printf("\nlist starting with hole test\n");
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

    printf("\nlist starting with process test\n");
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

    printf("\nmergeFreeBlocks TESTS BEGIN HERE\n");
    printf("empty list test\n");
    head = NULL;
    printMemory(head);
    printf("\n");
    mergeFreeBlocks(head);
    printMemory(head);

    printf("\nOne process test\n");
    head = NULL;
    push(&head, false, 1, 0, 10);
    printMemory(head);
    printf("\n");
    mergeFreeBlocks(head);
    printMemory(head);

    printf("\ntwo process test\n");
    head = NULL;
    push(&head, false, 2, 10, 12);
    push(&head, false, 1, 0, 10);
    printMemory(head);
    printf("\n");
    mergeFreeBlocks(head);
    printMemory(head);

    printf("\nOne hole test\n");
    head = NULL;
    push(&head, true, 0, 0, 10);
    printMemory(head);
    printf("\n");
    mergeFreeBlocks(head);
    printMemory(head);

    printf("\ntwo hole test\n");
    head = NULL;
    push(&head, true, 0, 10, 12);
    push(&head, true, 0, 0, 10);
    printMemory(head);
    printf("\n");
    mergeFreeBlocks(head);
    printMemory(head);

    printf("\nlist starting with hole test\n");
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
    mergeFreeBlocks(head);
    printMemory(head);

    printf("\nlist starting with process test\n");
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
    mergeFreeBlocks(head);
    printMemory(head);

    freeLinkedList(&head);
    printf("\nIf freeLinkedList works, next print is empty\n");
    printMemory(head);
    return 0;
}