SELECT YEAR(differentiation_date) year, (max_size-size_of_colony) year_dev, id
FROM ecoli_data a JOIN (SELECT
                      YEAR(differentiation_date) year,
                      MAX(size_of_colony) max_size
                      FROM ecoli_data
                      GROUP BY YEAR(differentiation_date)) b
              ON YEAR(a.differentiation_date)=b.year
ORDER BY year, year_dev