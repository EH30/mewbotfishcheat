import mewbotfish

def main():
    mcheat = mewbotfish.FishCheat()
    user_input = input("Enter: ")
    for item in mcheat.run_search(user_input):
        print(item)

if __name__ == "__main__":
    main()
