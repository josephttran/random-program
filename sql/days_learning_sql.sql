DECLARE @history TABLE(Submission_Date DATE, Hacker_ID INT);
DECLARE @date_start DATE;
DECLARE @date_end DATE;

SET @date_start = '2016-03-01';
SET @date_end = '2016-03-15';

INSERT INTO @history
SELECT      
    Submission_date, 
    Hacker_ID 
FROM Submissions
WHERE Submission_date = @date_start
GROUP BY Submission_date, Hacker_ID

SET @date_start = DATEADD(DAY, 1, @date_start)

WHILE (@date_start <= @date_end)
BEGIN
    INSERT INTO @history
    SELECT 
        Submission_date,
        Hacker_ID
    FROM (SELECT
            Submission_date,
            CASE WHEN EXISTS (SELECT 1 
                              FROM @history 
                              WHERE Hacker_ID = Submissions.Hacker_ID
                                AND DATEDIFF(day, Submission_date, Submissions.Submission_date)=1
                             )
                THEN Hacker_ID
                ELSE NULL
            END AS Hacker_ID,
            Submission_ID
        FROM Submissions
        WHERE Submission_date = @date_start  
        ) AS Temp
    WHERE Hacker_ID IS NOT NULL
    GROUP BY Submission_date, Hacker_ID;
    
    SET @date_start = DATEADD(DAY, 1, @date_start)
END

;WITH Unique_hacker AS (
    SELECT
        ROW_NUMBER() OVER(ORDER BY Submission_date) AS Row_number,
        Submission_date,
        Total
    FROM (SELECT 
            Submission_date,
            COUNT(Hacker_ID) AS Total
          FROM @history
          GROUP BY Submission_date
          ) AS T
),
Max_hacker AS (
    SELECT  
        ROW_NUMBER() OVER(ORDER BY Submission_date) AS Row_number,
        Hacker_ID,
        Name 
    FROM (SELECT
            RANK() OVER(PARTITION BY Submission_date 
                        ORDER BY COUNT(Submission_date) DESC, S.Hacker_ID) AS Rk,
            Submission_date,
            S.Hacker_ID AS Hacker_ID,
            Name 
         FROM Submissions S
         INNER JOIN Hackers
            ON S.Hacker_ID = Hackers.Hacker_ID
         GROUP BY Submission_date, S.Hacker_ID, Name
        ) AS Temp
    WHERE Rk = 1
)

SELECT
    Submission_date,
    Total,
    Hacker_ID,
    Name 
FROM Unique_hacker
INNER JOIN Max_hacker
    ON Unique_hacker.Row_number = Max_hacker.Row_number
