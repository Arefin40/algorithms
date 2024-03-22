#include <bits/stdc++.h>
using namespace std;

typedef struct
{
   string id;
   int deadline, profit;
} Job;

void printJobs(vector<Job> &jobs)
{
   cout << endl;
   for (auto job : jobs)
      cout << setw(3) << job.id << " ";
   cout << endl;

   for (auto job : jobs)
      cout << setw(3) << job.deadline << " ";
   cout << endl;

   for (auto job : jobs)
      cout << setw(3) << job.profit << " ";
   cout << endl;
}

bool comparator(Job j1, Job j2)
{
   return j1.profit > j2.profit;
}

void ganttChart(vector<Job> &jobs, int chartSize)
{
   vector<string> chart(chartSize);

   for (auto job : jobs)
   {
      for (int j = job.deadline - 1; j >= 0; j--)
         if (chart[j] == "")
         {
            chart[j] = job.id;
            break;
         }
   }

   // Print chart
   cout << "\nJob sequence: ";
   for (auto x : chart)
      if (x != "")
         cout << x << " ";

   cout << endl;
}

int main()
{
   int n, i, max = -1;
   cout << "Enter the number of jobs: ";
   cin >> n;
   vector<Job> jobs(n);

   for (i = 0; i < n; i++)
   {
      cout << "Enter deadline and profit for job-" << (i + 1) << ": ";
      jobs[i].id = "J" + to_string(i + 1);
      cin >> jobs[i].deadline >> jobs[i].profit;

      if (jobs[i].deadline > max)
         max = jobs[i].deadline;
   }

   printJobs(jobs);
   sort(jobs.begin(), jobs.end(), comparator);
   printJobs(jobs);
   ganttChart(jobs, max);

   return 0;
}