#Path to project directory
PROJECT_DIR = YOUR_PATH_HERE

#Paths to project dependencies, note monitoring is optional
ARGUMENTS = PROJECT_DIR=$(PROJECT_DIR)

ifdef BUILD_32BIT_COMPATIBLE
    ARGUMENTS += BUILD_32BIT_COMPATIBLE=1
endif
ifdef MONITORING
    ARGUMENTS += MONITORING=1
endif

all:
	(cd $(PROJECT_DIR)/Framework; make $(ARGUMENTS))
ifdef MONITORING
	(cd $(PROJECT_DIR)/Monitoring; make $(ARGUMENTS))
endif
if test -d $(PROJECT_DIR)/FineGranularityContent
	(cd $(PROJECT_DIR)/FineGranularityContent; make $(ARGUMENTS))
endif
if test -d $(PROJECT_DIR)/LArContent
	(cd $(PROJECT_DIR)/LArContent; make $(ARGUMENTS))
endif

clean:
	(cd $(PROJECT_DIR)/Framework; make clean $(ARGUMENTS))
	(cd $(PROJECT_DIR)/Monitoring; make clean $(ARGUMENTS))
if test -d $(PROJECT_DIR)/FineGranularityContent
	(cd $(PROJECT_DIR)/FineGranularityContent; make clean $(ARGUMENTS))
endif
if test -d $(PROJECT_DIR)/LArContent
	(cd $(PROJECT_DIR)/LArContent; make clean $(ARGUMENTS))
endif
