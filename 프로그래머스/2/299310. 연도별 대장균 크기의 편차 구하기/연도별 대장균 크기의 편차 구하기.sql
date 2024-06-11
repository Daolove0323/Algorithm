select year(DIFFERENTIATION_DATE) year, (m-size_of_colony) year_dev, id
from ecoli_data a join (select year(DIFFERENTIATION_DATE) year, max(size_of_colony) m
                        from ecoli_data
                        group by year(DIFFERENTIATION_DATE)) b
                        on year(a.DIFFERENTIATION_DATE)=b.year
order by year, year_dev