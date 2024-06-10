select count(*) count
from ecoli_data
where !(genotype&2) and (genotype&5);