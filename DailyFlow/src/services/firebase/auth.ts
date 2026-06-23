import {
  GoogleAuthProvider,
  OAuthProvider,
  onAuthStateChanged,
  signInWithPopup,
  signOut,
  type Auth,
  type User,
} from 'firebase/auth';

export interface AuthService {
  onAuthStateChanged(callback: (user: User | null) => void): () => void;
  signInWithGoogle(): Promise<User>;
  signInWithApple(): Promise<User>;
  signOut(): Promise<void>;
}

export class FirebaseAuthService implements AuthService {
  constructor(private readonly auth: Auth) {}

  onAuthStateChanged(callback: (user: User | null) => void) {
    return onAuthStateChanged(this.auth, callback);
  }

  async signInWithGoogle() {
    const credential = await signInWithPopup(
      this.auth,
      new GoogleAuthProvider(),
    );
    return credential.user;
  }

  async signInWithApple() {
    const provider = new OAuthProvider('apple.com');
    provider.addScope('email');
    provider.addScope('name');

    const credential = await signInWithPopup(this.auth, provider);
    return credential.user;
  }

  signOut() {
    return signOut(this.auth);
  }
}
