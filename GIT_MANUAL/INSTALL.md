## How to get the repo
	1. Make Git Bash.
	2. Execute command : 'git clone https://github.com/ccmteamap/robot'

## If the repo did not clone
	1. Execute command : 'git remote add origin https://github.com/ccmteamap/robot'  

##	Pull & push

	1. Pull the git : 'git pull origin master'
	2. Push the git : 'git push origin master'

## ssh toegang (geen paswoorden invoeren bij elke push)

	1. genereer een keypaar : 'ssh-keygen'    (let goed op waar je deze opslaagt je hebt ze nodig)
	2. kopieer de publieke sleutel (ssh_id.pub)
	3. open github settings en ga naar 'ssh and GPG keys'
	4. klik op new ssh key
	5. plak de sleutel en saven die handel
	6. delete de huidige origin : 'git remote remove origin'
	7. maak een nieuwe origin aan : 'git remote add origin git@github.com:ccmteamap/robot.git'
