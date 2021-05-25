#define REG_SIZE 8
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
#define CLR_BIT(REG,BIT) (REG&=~(1<<BIT))
#define TOG_BIT(REG,BIT) (REG^=(1<<BIT))
#define READ_BIT(REG,BIT) ((REG&(1u<<BIT))>>BIT)
#define ROL(REG,NUM) (REG=((REG<<NUM)|(REG>>REG_SIZE-NUM)))
#define ROR(REG,NUM) (REG=((REG>>NUM)|(REG<<REG_SIZE-NUM)))
