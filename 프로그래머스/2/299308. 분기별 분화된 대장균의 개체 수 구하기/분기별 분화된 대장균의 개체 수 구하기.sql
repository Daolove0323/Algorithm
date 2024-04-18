SELECT CASE
WHEN MONTH(DIFFERENTIATION_DATE) in (1, 2, 3) THEN '1Q'
WHEN MONTH(DIFFERENTIATION_DATE) in (4, 5, 6) THEN '2Q'
WHEN MONTH(DIFFERENTIATION_DATE) in (7, 8, 9) THEN '3Q'
ELSE '4Q' END AS QUARTER, COUNT(*) AS ECOLI_COUNT
FROM ECOLI_DATA
GROUP BY QUARTER
ORDER BY QUARTER ASC