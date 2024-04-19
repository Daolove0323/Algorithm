SELECT a.id, a.genotype, b.genotype parent_genotype
FROM ecoli_data a LEFT JOIN (SELECT id, genotype
                           FROM ecoli_data) b
                           ON a.parent_id=b.id
WHERE a.genotype&b.genotype=b.genotype
ORDER BY id;