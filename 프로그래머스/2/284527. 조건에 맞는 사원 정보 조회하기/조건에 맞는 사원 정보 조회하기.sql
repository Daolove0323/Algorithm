select sum(score) score, c.emp_no, emp_name, position, email
from (hr_department a join hr_employees b on a.dept_id=b.dept_id)
join hr_grade c on b.emp_no=c.emp_no
group by emp_no
order by score desc
limit 1;