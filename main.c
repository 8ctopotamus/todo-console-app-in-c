#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DESCRIPTION_LENGTH 256
#define INITIAL_CAPACITY 10

typedef struct {
	int id;
	char description[MAX_DESCRIPTION_LENGTH];
	bool completed;
} TodoItem;

TodoItem* todo_list = NULL;
int todo_count = 0;
int todo_capacity = 0;
int next_id = 1;

void initialize_todo_list() {
	todo_capacity = INITIAL_CAPACITY;
	todo_list = (TodoItem*)malloc(sizeof(TodoItem) * todo_capacity);
	if (todo_list == NULL) {
		printf("Error: failed to allocate memory!");
		exit(EXIT_FAILURE);
	}

	todo_count = 0;
	next_id = 1;
}

void free_todo_list() {
	if (todo_list != NULL) {
		free(todo_list);
		todo_list = NULL;
	}
	
	todo_count = 0;
	todo_capacity = 0;
	next_id = 1;
}

int main(void) {
	int choice;

	initialize_todo_list();

	do {
		printf("\n--- Todo List Application---\n");
		printf("1. Add Todo\n");
		printf("2. List Todos\n");
		printf("3. Mark Todo as Complete\n");
		printf("4. Delete Todo\n");
		printf("5. Save Todos\n");
		printf("6 Exit\n");
		printf("Enter your choice\n");

		if (scanf("%d", &choice) != 1) {
			printf("Invalid input. Please enter a number\n");
			while (getchar() != '\n');
			continue;
		}

		// consume left over newline character
		while (getchar() != '\n');

		switch(choice) {
			case 1:
				break;
			case 6:
				printf("Exiting appliction. Have a great day!\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
		

	} while (choice != 6);

	free_todo_list();

	return 0;
}
