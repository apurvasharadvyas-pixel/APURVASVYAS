#include <iostream>
#include <string>
using namespace std;

const int TOTAL_STAGES = 5;

string farmingStages[TOTAL_STAGES] = {
    "Land Preparation",
    "Seeding",
    "Irrigation",
    "Fertilizer Application",
    "Harvesting"
};

int points[TOTAL_STAGES] = {10, 20, 15, 15, 30};

bool completed[TOTAL_STAGES] = {
    false, false, false, false, false
};

int main()
{
    int choice;
    int totalScore = 0;

    cout << "====================================\n";
    cout << "    FARMING SIMULATION GAME\n";
    cout << "====================================\n";

    do
    {
        cout << "\nFarming Menu\n";
        cout << "1. Land Preparation\n";
        cout << "2. Seeding\n";
        cout << "3. Irrigation\n";
        cout << "4. Fertilizer Application\n";
        cout << "5. Harvesting\n";
        cout << "6. View Farming Progress\n";
        cout << "7. View Total Score\n";
        cout << "8. Exit Game\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= TOTAL_STAGES)
        {
            int index = choice - 1;

            // Check whether the previous stage is completed
            if (index > 0 && !completed[index - 1])
            {
                cout << "\nComplete the previous farming stage first!\n";
            }
            else if (completed[index])
            {
                cout << "\nThis stage is already completed!\n";
            }
            else
            {
                completed[index] = true;
                totalScore += points[index];

                cout << "\n" << farmingStages[index]
                     << " completed successfully!\n";

                cout << "Points earned: "
                     << points[index] << "\n";

                cout << "Total score: "
                     << totalScore << "\n";
            }
        }
        else if (choice == 6)
        {
            cout << "\n--- Farming Progress ---\n";

            for (int i = 0; i < TOTAL_STAGES; i++)
            {
                cout << i + 1 << ". "
                     << farmingStages[i] << " : ";

                if (completed[i])
                    cout << "Completed\n";
                else
                    cout << "Pending\n";
            }
        }
        else if (choice == 7)
        {
            cout << "\nYour total score is: "
                 << totalScore << "\n";

            if (completed[TOTAL_STAGES - 1])
                cout << "Congratulations! Harvest completed!\n";
        }
        else if (choice == 8)
        {
            cout << "\nThank you for playing!\n";
            cout << "Final score: " << totalScore << "\n";
        }
        else
        {
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}