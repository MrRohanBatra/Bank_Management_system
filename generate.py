# l=["rohan","suyash","shubham"]
# source=["sources\cusomter\","sources\employee\"]
# count=0
# for j in source:
#     for i in l:
#         f=open(j+i+".txt","w")
#         count+=1
#         f.close()
l = ["rohan", "suyash", "shubham"]
source = ["sources\\customer\\", "sources\\employee\\"]
count = 0

for directory in source:
    for name in l:
        filepath = directory + name + ".txt"
        with open(filepath, "w") as f:
            count += 1

print(f"Total {count} files created.")
