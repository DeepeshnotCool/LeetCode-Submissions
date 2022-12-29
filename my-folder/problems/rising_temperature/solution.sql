# Write your MySQL query statement below
SELECT wt1.Id 
FROM Weather wt1, Weather wt2
WHERE wt1.Temperature > wt2.Temperature AND 
      datediff(wt1.recordDate,wt2.recordDate)=1;