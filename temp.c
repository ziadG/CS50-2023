bool vote(string name)
{
    // looping through the array and increminting the total votes by 1
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    string name;
    int vote;
    for (int i = 0; i < candidate_count; i++)
    {
        // bubbule sorting the array
        if (candidates[i].votes > candidates[i + 1].votes)
        {
            name = candidates[i].name;
            vote = candidates[i].votes;
            candidates[i].name = candidates[i + 1].name;
            candidates[i].votes = candidates[i + 1].votes;
            candidates[i + 1].name = name;
            candidates[i + 1].votes = vote;
            i = -1;
        }
    }
    // checking for the winner and printing all candidates in case of tie
    for (int j = 0; j <= candidate_count; j++)
    {
        if (candidates[candidate_count].votes > candidates[candidate_count - 1].votes)
        {
            printf("%s \n", candidates[candidate_count].name);
            return;
        }
        else if (candidates[candidate_count].votes == candidates[j].votes)
        {
            printf("%s \n", candidates[j].name);
        }
    }
    return;
}