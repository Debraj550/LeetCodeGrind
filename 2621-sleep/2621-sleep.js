async function sleep(millis) {
  return new Promise((res,rej) => {
    try {
      setTimeout(() => res(1), millis)
    } catch(err) {
      rej(err)
    }
  })
}