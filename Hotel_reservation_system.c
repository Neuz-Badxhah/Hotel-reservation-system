#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 50
#define MAX_ROOMS 10

struct reservation
{
    int room_number;
    char guest_name[50];
    int num_guests;
};

struct room
{
    int number;
    int capacity;
    int price;
    int reserved;
};

struct room rooms[MAX_ROOMS] = {
    {1, 2, 50, 0},
    {2, 2, 50, 0},
    {3, 2, 50, 0},
    {4, 2, 50, 0},
    {5, 3, 75, 0},
    {6, 3, 75, 0},
    {7, 3, 75, 0},
    {8, 4, 100, 0},
    {9, 4, 100, 0},
    {10, 4, 100, 0}};

struct reservation reservations[MAX_GUESTS];
int num_reservations = 0;

void display_menu()
{
    printf("\nWelcome to the Hotel Reservation System\n");
    printf("========================================\n");
    printf("1. Reserve a room\n");
    printf("2. View reservations\n");
    printf("3. Cancel a reservation\n");
    printf("4. Exit\n");
}

void reserve_room()
{
    int room_number, num_guests, i;
    char guest_name[50];

    printf("\nEnter guest name: ");
    scanf("%s", guest_name);
    printf("Enter number of guests: ");
    scanf("%d", &num_guests);
    printf("Enter room number: ");
    scanf("%d", &room_number);

    if (room_number < 1 || room_number > MAX_ROOMS)
    {
        printf("Invalid room number.\n");
        return;
    }

    if (rooms[room_number - 1].reserved == 1)
    {
        printf("Room is already reserved.\n");
        return;
    }

    if (num_reservations >= MAX_GUESTS)
    {
        printf("No more reservations can be made.\n");
        return;
    }

    if (num_guests > rooms[room_number - 1].capacity)
    {
        printf("Room cannot accommodate that many guests.\n");
        return;
    }

    // reserve the room
    rooms[room_number - 1].reserved = 1;

    // add the reservation to the list
    reservations[num_reservations].room_number = room_number;
    strcpy(reservations[num_reservations].guest_name, guest_name);
    reservations[num_reservations].num_guests = num_guests;

    printf("Reservation made successfully.\n");
    num_reservations++;
}

void view_reservations()
{
    int i;

    printf("\nReservations:\n");
    printf("-------------\n");

    if (num_reservations == 0)
    {
        printf("No reservations found.\n");
        return;
    }

    for (i = 0; i < num_reservations; i++)
    {
        printf("Guest Name: %s\n", reservations[i].guest_name);
        printf("Room Number: %d\n", reservations[i].room_number);
        printf("Number of Guests: %d\n\n", reservations[i].num_guests);
    }
}

void cancel_reservation()
{
    int i, room_number;

    printf("\nEnter room number");
}
int main()
{
    int option;

    do
    {
        display_menu();

        printf("\nEnter an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            reserve_room();
            break;
        case 2:
            view_reservations();
            break;
        case 3:
            cancel_reservation();
            break;
        case 4:
            printf("\nThank you for using the Hotel Reservation System.\n");
            break;
        default:
            printf("\nInvalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}

