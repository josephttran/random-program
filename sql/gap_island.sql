;WITH CteProjects AS (
    SELECT 
        LAG(Start_date) OVER(ORDER BY Start_date) AS LagStartDate,
        Start_date,
        End_date,
        LEAD(start_date) OVER(ORDER BY Start_date) AS LeadStartDate
    from projects
), StartDate AS (
    SELECT 
        Row_number() OVER(ORDER BY Start_date) AS Rn,
        start_date
    FROM CteProjects
    WHERE LagStartDate IS NULL
        OR DATEDIFF(day, LagStartDate, Start_date) <> 1
), EndDate AS (
    SELECT 
        Row_number() OVER(ORDER BY Start_date) AS Rn,
        end_date
    FROM CteProjects
    WHERE LeadStartDate IS NULL
        OR DATEDIFF(day, End_date, LeadStartDate) <> 0
)

SELECT Start_date, End_date
FROM StartDate
INNER JOIN EndDate
    ON StartDate.Rn = EndDate.Rn
ORDER BY DATEDIFF(day, Start_date, End_date), Start_date
