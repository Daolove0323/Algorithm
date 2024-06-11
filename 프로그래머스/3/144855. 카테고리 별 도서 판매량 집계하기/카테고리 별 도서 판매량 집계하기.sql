select category, sum(sales) total_sales
from book a join book_sales b on a.book_id=b.book_id
where sales_date like '2022-01%'
group by category
order by category;