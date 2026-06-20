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

void add_todo(const char* description) {	
	int len = strlen(description);
	
	printf("Saving '%s'. len: %d\n", description, len);


	if (len == 0) {
		printf("Error: description cannot be empty\n");
		return;
	}
}

int main(void) {
	initialize_todo_list();

	int choice;
	char temp_description[MAX_DESCRIPTION_LENGTH];
	int temp_id;

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
				printf("Enter the new todo description: ");
				fgets(temp_description, sizeof(temp_description), stdin);
				temp_description[strcspn(temp_description, "\n")] = 0; // remove the "\n" from user input
				add_todo(temp_description);
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
